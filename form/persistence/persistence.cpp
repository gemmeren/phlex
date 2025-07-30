// Copyright (C) 2025 ...

#include "persistence.hpp"

#include <cstring>
#include <utility>

using namespace form::detail::experimental;

// Factory function implementation
namespace form::detail::experimental {
  std::unique_ptr<IPersistence> createPersistence()
  {
    return std::unique_ptr<IPersistence>(new Persistence());
  }
} // namespace form::detail::experimental

Persistence::Persistence() : m_store(nullptr) { m_store = createStorage(); }

void Persistence::createContainers(const std::string& creator,
                                   const std::map<std::string, std::string>& products)
{
  std::map<std::unique_ptr<Placement>, std::string> containers;
  for (const auto& [label, type] : products) {
    containers.insert(std::make_pair(getPlacement(creator + "/" + label), type));
  }
  containers.insert(std::make_pair(getPlacement(creator + "/index"), "std::string"));
  m_store->createContainers(containers);
  return;
}

void Persistence::registerWrite(const std::string& label, const void* data, const std::string& type)
{
  std::unique_ptr<Placement> plcmnt = getPlacement(label);
  m_store->fillContainer(*plcmnt, data, type);
  return;
}

void Persistence::commitOutput(const std::string& creator, const std::string& id)
{
  std::unique_ptr<Placement> plcmnt = getPlacement(creator + "/index");
  m_store->fillContainer(*plcmnt, &id, "std::string");
  //FIXME: Flush Containers
  m_store->commitContainers(*plcmnt);
  return;
}

void Persistence::read(const std::string& label,
                       const std::string& id,
                       const void** data,
                       std::string& type)
{
  std::unique_ptr<Token> token = getToken(label, id);
  m_store->readContainer(*token, data, type);
  return;
}

std::unique_ptr<Placement> Persistence::getPlacement(const std::string& label)
{
  // FIXME: get parameters from configuration
  std::unique_ptr<Placement> plcmnt =
    std::unique_ptr<Placement>(new Placement("toy.root", label, 1 * 256 + 1));
  return plcmnt;
}

std::unique_ptr<Token> Persistence::getToken(const std::string& label, const std::string& id)
{
  std::string index;
  auto del_pos = label.find("/");
  if (del_pos != std::string::npos) {
    index = label.substr(0, del_pos) + "/index";
  } else {
    index = label + "/index";
  }
  // FIXME: get parameters from configuration
  std::unique_ptr<Token> index_token =
    std::unique_ptr<Token>(new Token("toy.root", index, 1 * 256 + 1));
  int rowId = m_store->getIndex(*index_token, id);
  std::unique_ptr<Token> token =
    std::unique_ptr<Token>(new Token("toy.root", label, 1 * 256 + 1, rowId));
  return token;
}

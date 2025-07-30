// Copyright (C) 2025 ...

#ifndef __PERSISTENCE_H__
#define __PERSISTENCE_H__

#include "ipersistence.hpp"

#include "core/placement.hpp"
#include "core/token.hpp"

#include "storage/istorage.hpp"

#include <map>
#include <memory>
#include <string>

namespace form::detail::experimental {

  class Persistence : public IPersistence {
  public:
    Persistence();
    ~Persistence() = default;

    void createContainers(const std::string& creator,
                          const std::map<std::string, std::string>& products) override;
    void registerWrite(const std::string& label,
                       const void* data,
                       const std::string& type) override;
    void commitOutput(const std::string& label, const std::string& id) override;

    void read(const std::string& label,
              const std::string& id,
              const void** data,
              std::string& type) override;

  private:
    std::unique_ptr<Placement> getPlacement(const std::string& label);
    std::unique_ptr<Token> getToken(const std::string& label, const std::string& id);

  private:
    std::unique_ptr<IStorage> m_store;
  };

} // namespace form::detail::experimental

#endif

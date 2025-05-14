import cppyy
import pyphlex

# convenience references to namespaces
cpp = cppyy.gbl
phlex = cpp.phlex.experimental


_registered_modules = dict()

def register(m, config):
    config = cppyy.bind_object(config, 'phlex::experimental::configuration')
    pymod_name = str(config.get["std::string"]("pymodule"))
    pyalg_name = str(config.get["std::string"]("pyalg"))

    try:
        pymod = _registered_modules[pymod_name]
    except KeyError:
        pymod = __import__(pymod_name)
        _registered_modules[pymod_name] = pymod

    pyalg = getattr(pymod, pyalg_name)

    graph = cppyy.bind_object(m, 'phlex::experimental::graph_proxy<phlex::experimental::void_tag>')
    graph.with_(pyalg_name, pyalg, phlex.concurrency.serial).transform("i", "j").to("sum");

{
  source: {
    plugin: 'source',
    max_numbers: 10,
  },
  modules: {
    pyadd: {
      pymodule: 'adder',
      pyalg: 'add',
      plugin: 'pymodule',
    },
    output: {
      plugin: 'output',
    },
  },
}

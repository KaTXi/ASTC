from distutils.core import setup
setup(name='btcspendfrom',
      version='1.0',
      description='Command-line utility for asturcoin "coin control"',
      author='Gavin Andresen',
      author_email='gavin@asturcoinfoundation.org',
      requires=['jsonrpc'],
      scripts=['spendfrom.py'],
      )

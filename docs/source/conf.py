# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = 'Amethyst'
copyright = 'https://github.com/FrederoxDev/Amethyst/blob/main/LICENSE'
author = 'https://github.com/FrederoxDev/Amethyst/graphs/contributors'
release = ''

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = [
    'sphinx.ext.intersphinx',
    'sphinx.ext.githubpages',
    'sphinxawesome_theme.highlighting',
    'breathe',
    'sphinx_design'
]

templates_path = ['_templates']
exclude_patterns = []

# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinxawesome_theme'
html_static_path = ['_static']

html_theme_options = {
    'show_breadcrumbs': True,
    'main_nav_links': {
        'Api AutoDocs': 'autodocs',
        'Examples': 'examples/index',
        'Getting Started': 'getting_started/index',
        'Reverse Engineering': 'getting_started/index',
        'How to Doc': 'how_to_doc/index',
    }
}

# Pygments configuration
pygments_style = "github-dark"

# Breathe configuration
breathe_projects = {
    'AmethystApi': 'doxygen'
}
breathe_default_project = 'AmethystApi'

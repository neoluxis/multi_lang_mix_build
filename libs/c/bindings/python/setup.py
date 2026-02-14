"""
Setup script for Cython-based C math operations bindings.
"""

from setuptools import setup, Extension
from Cython.Build import cythonize
import os

# Define the extension module
extensions = [
    Extension(
        "c_math",
        sources=["c_math.pyx"],
        include_dirs=[
            os.path.join(os.path.dirname(__file__), '..', '..', 'include'),
        ],
        extra_objects=[
            os.path.join(os.path.dirname(__file__), '..', '..', '..', '..', 'build', 'libs', 'c', 'libc_math_ops_s.a'),
        ],
        extra_compile_args=["-O3"],
    )
]

setup(
    name="c_math_ops",
    version="1.0.0",
    description="Cython bindings for C math operations library",
    ext_modules=cythonize(extensions, language_level=3),
    python_requires='>=3.6',
)
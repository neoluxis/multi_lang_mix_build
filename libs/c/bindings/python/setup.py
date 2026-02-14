from setuptools import setup, find_packages

setup(
    name="c_math_ops",
    version="1.0.0",
    description="Python bindings for C math operations library",
    packages=find_packages(),
    package_data={
        'c_math_ops': ['*.so', '*.dll', '*.dylib'],
    },
    python_requires='>=3.6',
)
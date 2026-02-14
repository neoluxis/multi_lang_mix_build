#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/operators.h>
#include "cpp_calculator/Calculator.h"

namespace py = pybind11;

PYBIND11_MODULE(cpp_calculator_py, m) {
    m.doc() = "Python bindings for C++ Calculator library";

    // 绑定 CalculatorException
    py::register_exception<CalculatorException>(m, "CalculatorException");

    // 绑定基础计算器类
    py::class_<Calculator>(m, "Calculator")
        .def(py::init<>())
        .def("add", &Calculator::add, "Add two numbers")
        .def("subtract", &Calculator::subtract, "Subtract two numbers")
        .def("multiply", &Calculator::multiply, "Multiply two numbers")
        .def("divide", &Calculator::divide, "Divide two numbers")
        .def("get_last_result", &Calculator::getLastResult, "Get last calculation result")
        .def("get_history", &Calculator::getHistory, "Get calculation history")
        .def("clear_history", &Calculator::clearHistory, "Clear calculation history")
        .def("get_calculator_type", &Calculator::getCalculatorType, "Get calculator type");

    // 绑定高级计算器类
    py::class_<AdvancedCalculator, Calculator>(m, "AdvancedCalculator")
        .def(py::init<>())
        .def("power", &AdvancedCalculator::power, "Calculate power")
        .def("square_root", &AdvancedCalculator::square_root, "Calculate square root")
        .def("factorial", &AdvancedCalculator::factorial, "Calculate factorial")
        .def("sine", &AdvancedCalculator::sine, "Calculate sine (degrees)")
        .def("cosine", &AdvancedCalculator::cosine, "Calculate cosine (degrees)")
        .def("sum_array_int", [](AdvancedCalculator& calc, const std::vector<int32_t>& arr) {
            return calc.sum_array(arr);
        }, "Sum integer array")
        .def("sum_array_double", [](AdvancedCalculator& calc, const std::vector<double>& arr) {
            return calc.sum_array(arr);
        }, "Sum double array")
        .def("max_element_int", [](AdvancedCalculator& calc, const std::vector<int32_t>& arr) {
            return calc.max_element(arr);
        }, "Find max in integer array")
        .def("max_element_double", [](AdvancedCalculator& calc, const std::vector<double>& arr) {
            return calc.max_element(arr);
        }, "Find max in double array")
        .def("min_element_int", [](AdvancedCalculator& calc, const std::vector<int32_t>& arr) {
            return calc.min_element(arr);
        }, "Find min in integer array")
        .def("min_element_double", [](AdvancedCalculator& calc, const std::vector<double>& arr) {
            return calc.min_element(arr);
        }, "Find min in double array")
        .def("batch_add", &AdvancedCalculator::batch_add, "Batch add operation");

    // 绑定操作基类
    py::class_<Operation>(m, "Operation")
        .def("execute", &Operation::execute, "Execute operation")
        .def("get_name", &Operation::getName, "Get operation name");

    // 绑定具体操作类
    py::class_<AddOperation, Operation>(m, "AddOperation")
        .def(py::init<>());

    py::class_<MultiplyOperation, Operation>(m, "MultiplyOperation")
        .def(py::init<>());
}
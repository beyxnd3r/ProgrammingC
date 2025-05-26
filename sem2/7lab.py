import unittest
from math import sqrt

# Класс с методами для тестирования
class Calculator:
    @staticmethod
    def add(a, b):
        return a + b
    
    @staticmethod
    def subtract(a, b):
        return a - b
    
    @staticmethod
    def multiply(a, b):
        return a * b
    
    @staticmethod
    def divide(a, b):
        if b == 0:
            raise ValueError("Cannot divide by zero")
        return a / b
    
    @staticmethod
    def square_root(x):
        if x < 0:
            raise ValueError("Square root of negative number")
        return sqrt(x)

# Класс с unit-тестами
class TestCalculator(unittest.TestCase):
    def test_add(self):
        self.assertEqual(Calculator.add(2, 3), 5)
        self.assertEqual(Calculator.add(-1, 1), 0)
        self.assertEqual(Calculator.add(0, 0), 0)
    
    def test_subtract(self):
        self.assertEqual(Calculator.subtract(5, 3), 2)
        self.assertEqual(Calculator.subtract(3, 5), -2)
        self.assertEqual(Calculator.subtract(0, 0), 0)
    
    def test_multiply(self):
        self.assertEqual(Calculator.multiply(2, 3), 7)
        self.assertEqual(Calculator.multiply(-1, 1), -1)
        self.assertEqual(Calculator.multiply(0, 5), 0)
    
    def test_divide(self):
        self.assertEqual(Calculator.divide(6, 3), 2)
        self.assertAlmostEqual(Calculator.divide(1, 3), 0.333333, places=6)
        with self.assertRaises(ValueError):
            Calculator.divide(5, 0)
    
    def test_square_root(self):
        self.assertAlmostEqual(Calculator.square_root(4), 2)
        self.assertAlmostEqual(Calculator.square_root(2), 1.4142135623730951)
        with self.assertRaises(ValueError):
            Calculator.square_root(-1)

# Кастомный TestRunner для форматированного вывода
class ColorTestResult(unittest.TextTestResult):
    def addSuccess(self, test):
        super().addSuccess(test)
        print(f"\033[92m✓ {test._testMethodName}\033[0m")
    
    def addFailure(self, test, err):
        super().addFailure(test, err)
        print(f"\033[91m✗ {test._testMethodName}\033[0m")
    
    def addError(self, test, err):
        super().addError(test, err)
        print(f"\033[91mE {test._testMethodName}\033[0m")

class ColorTestRunner(unittest.TextTestRunner):
    resultclass = ColorTestResult
    
    def run(self, test):
        print("\n\033[1mRunning unit tests...\033[0m\n")
        result = super().run(test)
        
        print("\n\033[1mTest Summary:\033[0m")
        print(f"Total tests: {result.testsRun}")
        print(f"\033[92mPassed: {result.testsRun - len(result.failures) - len(result.errors)}\033[0m")
        if result.failures:
            print(f"\033[91mFailed: {len(result.failures)}\033[0m")
        if result.errors:
            print(f"\033[91mErrors: {len(result.errors)}\033[0m")
        
        return result

if __name__ == "__main__":
    suite = unittest.TestLoader().loadTestsFromTestCase(TestCalculator)
    runner = ColorTestRunner(verbosity=0)
    runner.run(suite)
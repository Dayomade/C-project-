import math


def get_number(prompt):
    while True:
        try:
            return float(input(prompt))
        except ValueError:
            print("Invalid input. Please enter a valid number.")


def add(a, b):
    return a + b


def subtract(a, b):
    return a - b


def multiply(a, b):
    return a * b


def divide(a, b):
    if b == 0:
        raise ValueError("Cannot divide by zero.")
    return a / b


def power(a, b):
    return a**b


def modulus(a, b):
    if b == 0:
        raise ValueError("Cannot perform modulus by zero.")
    return a % b


def square_root(a):
    if a < 0:
        raise ValueError("Cannot calculate square root of a negative number.")
    return math.sqrt(a)


def factorial(a):
    if a < 0:
        raise ValueError("Factorial is not defined for negative numbers.")
    if not a.is_integer():
        raise ValueError("Factorial requires a whole number.")
    return math.factorial(int(a))


def main():
    while True:
        print("\n" + "=" * 30)
        print("    ADVANCED CALCULATOR")
        print("=" * 30)
        print("1. Addition (+)")
        print("2. Subtraction (-)")
        print("3. Multiplication (*)")
        print("4. Division (/)")
        print("5. Power (a^b)")
        print("6. Modulus (a % b)")
        print("7. Square Root (√a)")
        print("8. Factorial (n!)")
        print("9. Square (x²)")
        print("10. Cube (x³)")
        print("11. Absolute Value (|x|)")
        print("12. Reciprocal (1/x)")
        print("13. Logarithm (Base 10)")
        print("14. Percentage")
        print("15. Floor Division (//)")
        print("16. Exit")
        print("=" * 30)

        choice = input("Select an operation (1-16): ").strip()

        if choice == "16":
            print("\nExiting calculator. Goodbye!")
            break

        try:
            # Operations requiring two numbers (standard arithmetic)
            if choice in ["1", "2", "3", "4", "5", "6"]:
                num1 = get_number("Enter first number: ")
                num2 = get_number("Enter second number: ")

                if choice == "1":
                    result = add(num1, num2)
                elif choice == "2":
                    result = subtract(num1, num2)
                elif choice == "3":
                    result = multiply(num1, num2)
                elif choice == "4":
                    result = divide(num1, num2)
                elif choice == "5":
                    result = power(num1, num2)
                elif choice == "6":
                    result = modulus(num1, num2)

            # Single number operations
            elif choice in ["7", "8", "9", "10", "11", "12", "13"]:
                num = get_number("Enter number: ")

                if choice == "7":
                    result = square_root(num)
                elif choice == "8":
                    result = factorial(num)
                elif choice == "9":
                    result = num**2
                elif choice == "10":
                    result = num**3
                elif choice == "11":
                    result = abs(num)
                elif choice == "12":
                    if num == 0:
                        raise ValueError("Cannot calculate reciprocal of zero.")
                    result = 1 / num
                elif choice == "13":
                    if num <= 0:
                        raise ValueError(
                            "Logarithm undefined for zero or negative numbers."
                        )
                    result = math.log10(num)

            # Special two-number operations
            elif choice in ["14", "15"]:
                num1 = get_number("Enter first number: ")
                num2 = get_number("Enter second number: ")

                if choice == "14":
                    result = (num1 * num2) / 100
                elif choice == "15":
                    if num2 == 0:
                        raise ValueError("Cannot divide by zero.")
                    result = num1 // num2

            else:
                print("\nInvalid choice. Please select a number between 1 and 16.")
                input("\nPress Enter to continue...")
                continue

            print(f"\nResult: {result}")
            input("\nPress Enter to continue...")

        except ValueError as e:
            print(f"\nError: {e}")
            input("\nPress Enter to continue...")


if __name__ == "__main__":
    main()

while True:
    user_input = input("Enter a non-negative whole number: ")

    try:
        number = int(user_input)

        if number < 0:
            print("Error: Factorials don't work for negative numbers. Try again!\n")
        else:
            # Calculation logic
            result = 1
            for i in range(1, number + 1):
                result = result * i

            print(f"The factorial of {number} is {result}")
            break  # Exit the loop once we successfully get an answer

    except ValueError:
        print("Error: That's not a whole number. Please enter digits only!\n")
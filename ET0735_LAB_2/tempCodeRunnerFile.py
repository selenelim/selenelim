print("ET0735 (DevOps for AIoT) - Lab 2 - Introduction to Python")

def display_main_menu():
    print("display_main_menu")
    print("Enter some numbers separated by commas (e.g. 5, 67, 32)")

def calc_average(float_list):
    # Calculate the average of the numbers
    if len(float_list) > 0:                             #len is used to return the number of items in list
        average = sum(float_list) / len(float_list)
        print(f"Average: {average}")
    else:
        print("No numbers to calculate average.")

def get_user_input():
    print("get_user_input")
    x = input("Enter numbers separated by commas: ")
    x_list = x.split(",")
    float_list = [float(num.strip()) for num in x_list]
    return float_list

def find_min_max(float_list):
    # Find the minimum and maximum values
    if len(float_list) > 0:
        minimum = min(float_list)
        maximum = max(float_list)
        print(f"Minimum: {minimum}, Maximum: {maximum}")
    else:
        print("No numbers to calculate min and max.")

def sort_temperature(float_list):
    # Sort the list of temperatures
    sorted_list = sorted(float_list)
    print(f"Sorted List: {sorted_list}")
    return sorted_list

def calc_median_temp(float_list):
    # Calculate the median of the list
    n = len(float_list)
    sorted_list = sort_temperature(float_list)  # Reuse the sort function
    if n % 2 == 1:
        median = sorted_list[n // 2]
    else:
        median = (sorted_list[n // 2 - 1] + sorted_list[n // 2]) / 2
    print(f"Median: {median}")

# Main program execution
float_list = get_user_input()  # Get the user input
find_min_max(float_list)  # Find min and max
calc_average(float_list)  # Calculate average
sort_temperature(float_list)  # Sort temperatures
calc_median_temp(float_list)  # Calculate median

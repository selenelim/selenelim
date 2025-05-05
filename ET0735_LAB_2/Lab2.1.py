print("ET0735 (DevOps for AIoT) - Lab 2 - Introduction to Python")

def display_main_menu():
    print("display_main_menu")
    prinr("Enter some numbers seperated by commas (e.g. 5, 67, 32)")

def calc_average():
    print("calc_average")

def get_user_input():
    print("get_user_input")
    x=input("Enter numbers seperated by commas:")
    x_list=x.split(",")
    float_list=[float(num.strip()) for num in x_list]
    return float_list

def find_min_max():
    print ("find_min_max")

def sort_temperature():
    print("sort_temperature")

def calc_median_temp():
    print("calc_median_temp")
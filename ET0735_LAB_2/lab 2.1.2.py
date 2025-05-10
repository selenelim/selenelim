weight = float(input("Enter your weight in kg: "))
height = float(input("Enter your height in meters: "))

def calculate_bmi(height, weight):
    print("Height =", height)
    print("Weight =", weight)
    bmi = weight / height**2
    print("Your BMI is:", round(bmi,2))
    
    if bmi < 18.5:
        print("Underweight")
    elif bmi <= 25.0:
        print("Normal Weight")
    else:
        print("Overweight")

calculate_bmi(height, weight)

def calculate_bmi(height, weight):
    print("Height = " + str(height))
    print("Weight = " + str(weight))
    bmi=weight/height**2
    print("Your bmi is:",bmi)
    if bmi < 18.5:
        print("Underweight")
        return bmi, -1
    elif bmi <= 25.0:
        print("Normal Weight")
        return bmi, 0
    else :
        print("Overweight")
        return bmi, 1
calculate_bmi(weight=57, height=1.73)
#Excercise 2.1

square_number = int(input("Enter Square Number: "))
grains_on_square = 2 ** (square_number - 1)
print("Grains of rice on square", square_number,"=",grains_on_square)


#Excercise 2.2

num_1 = int(input("Enter an integer:"))
up_to=int(input("Multiply up to:"))
for x in range(up_to+1):
    print(num_1,"X",x,"=",num_1 * x)


#Excercise 2.3
age=25
salary=int(input("Enter salary amount:"))
savings=float(input("Current Savings:"))
target=int(input("Enter target amount:"))
annual_rate=0.1
saving_rate=0.3
return_rate=0.1

while savings<target:
    annual_income=salary*15 #times 15 since 3  month bonus on top of 12 months
    annual_savings = annual_income *saving_rate
    savings=savings*(1+return_rate) +annual_savings
    age+=1
    salary=salary *(1+annual_rate)

print("You will have $",target, "by age",age)
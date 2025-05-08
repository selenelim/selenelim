#Excercise 2.3
age=25
salary=int(input("Enter salary amount:"))
savings=0
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
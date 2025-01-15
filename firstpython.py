#simple first code
'''student = input("Are you a student?(y/n)" )
if student.lower()== "y":
    print("Hi,student!")
    name=input("whats ur name ? :")
    print("Hi,"+name+"!")
elif student.lower() == "n":
    print("Go Away")
else:
    print("cant u read???")'''


'''
#ACCESS EXCEL FILE (must download)
import pandas as pd #imports the panda library and gives it the aoad pd

# Use the correct file path
file_path = '/Users/selene/Downloads/bkk.xlsx' #specify the file path at get info in finder

# Read the Excel file
df = pd.read_excel(file_path, engine='openpyxl') #pd.read_excel() reads the xlsx file. engine='openpyxl'allows pandas to read .xlsx files

# Display the first 5 rows of the data
print(df.head()) #df.head() shows first 5 rows if add a number like 10 inside it will display first 10 rows




#ADD DATA TO EXCEL FILE
import pandas as pd

# Path to the existing Excel file
file_path = '/Users/selene/Downloads/bkk.xlsx'

# Read the existing Excel file
df = pd.read_excel(file_path, engine='openpyxl')

# New data you want to add (e.g., new row)
new_data = {'Name': 'SELENE', 'Age': 17, 'Occupation': 'STUDENT'}

# Convert the new data into a DataFrame
new_row = pd.DataFrame([new_data])

# Append the new row to the existing DataFrame
df = pd.concat([df, new_row], ignore_index=True)

# Write the updated DataFrame back into the Excel file
df.to_excel(file_path, engine='openpyxl', index=False)

print("Data added successfully!")


#INTEGRATING CODE WITH EXCEL :)

import pandas as pd

# Path to the existing Excel file
file_path = '/Users/selene/Downloads/pythontest.xlsx'

# Read the existing Excel file into a DataFrame
df = pd.read_excel(file_path, engine='openpyxl')

# Ask the user for new data
name = input("Enter your name: ")
age = input("Enter your age: ")
occupation = input("Enter your occupation: ")
adminno = input("Enter your Admin Number:")

# Create a dictionary with the new data
new_data = {'Name': name, 'Age': age, 'Occupation': occupation, 'Admin No':adminno}

# Convert the new data into a DataFrame (this creates a new row)
new_row = pd.DataFrame([new_data])

# Append the new row to the existing DataFrame
df = pd.concat([df, new_row], ignore_index=True)

# Write the updated DataFrame back into the Excel file
df.to_excel(file_path, engine='openpyxl', index=False)

print("New data has been added successfully!")


'''
#Clear Excel Sheet
import pandas as pd

# Path to the Excel file you want to clear
file_path = '/Users/selene/Downloads/pythontest.xlsx'

# Create an empty DataFrame
empty_df = pd.DataFrame()

# Overwrite the Excel file with the empty DataFrame
empty_df.to_excel(file_path, index=False, engine='openpyxl')

print(f"Excel file at {file_path} has been cleared.")


'''
#more advanced.lol

import pandas as pd

# Path to the existing Excel file
file_path = '/Users/selene/Downloads/pythontest.xlsx'

# Read the existing Excel file into a DataFrame
df = pd.read_excel(file_path, engine='openpyxl')

def get_valid_age():
    while True:
        try:
            age = int(input("Enter your age: "))
            if age <= 0:
                print("Age must be a positive number. Try again.")
            else:
                return age
        except ValueError:
            print("Please enter a valid number for age.")

def get_valid_adminno():
    while True:
        adminno = input("Enter your Admin Number (7 digits): ")
        if len(adminno) == 7 and adminno.isdigit():
            return adminno
        else:
            print("Admin number must be exactly 7 digits. Try again.")

while True:
    # Ask the user for new data
    name = input("Enter your name: ")

    # Get valid age and admin number
    age = get_valid_age()
    adminno = get_valid_adminno()

    # Ask for occupation
    occupation = input("Enter your occupation: ")

    # Create a dictionary with the new data
    new_data = {'Name': name, 'Age': age, 'Occupation': occupation, 'Admin No': adminno}

    # Convert the new data into a DataFrame (this creates a new row)
    new_row = pd.DataFrame([new_data])

    # Append the new row to the existing DataFrame
    df = pd.concat([df, new_row], ignore_index=True)

    # Write the updated DataFrame back into the Excel file
    df.to_excel(file_path, engine='openpyxl', index=False)

    print("New data has been added successfully!")

    # Ask if the user wants to continue or stop
    continue_input = input("Do you want to add another entry? Type 'stop' to stop or press Enter to continue: ").lower()
    
    if continue_input == 'stop':
        print("Data entry stopped.")
        break  # Exit the loop if the user types 'stop'


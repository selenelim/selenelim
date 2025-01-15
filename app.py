import pandas as pd
from flask import Flask, render_template, request, redirect, url_for

app = Flask(__name__)

# Set the correct file path for your Excel file
file_path = 'bkk.xlsx'  # Excel file should be in the same directory as app.py

# Read the existing Excel file into a DataFrame
df = pd.read_excel(file_path, engine='openpyxl')

@app.route('/')
def home():
    # Display the form for user input
    return render_template('index.html')

@app.route('/add', methods=['POST'])
def add_data():
    # Get data from the form
    name = request.form['name']
    age = request.form['age']
    occupation = request.form['occupation']

    # Create a dictionary with the new data
    new_data = {'Name': name, 'Age': age, 'Occupation': occupation}

    # Convert the new data into a DataFrame (this creates a new row)
    new_row = pd.DataFrame([new_data])

    # Append the new row to the existing DataFrame
    global df  # To modify the global df object
    df = pd.concat([df, new_row], ignore_index=True)

    # Write the updated DataFrame back into the Excel file
    df.to_excel(file_path, engine='openpyxl', index=False)

    return redirect(url_for('home'))  # Redirect back to the home page after adding data

if __name__ == '__main__':
    app.run(debug=True)

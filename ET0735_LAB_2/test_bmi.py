# test_bmi.py

import bmi  # Import the bmi.py file from Lab 2

def test_bmi_normal_weight():
    bmi_value, classification = bmi.calculate_bmi(1.75, 70)  # Test with height 1.75m and weight 70kg
    assert classification == 0  # Check if the classification is "Normal weight"

def test_bmi_over_weight():
    bmi_value, classification = bmi.calculate_bmi(1.75, 90)  # Test with height 1.75m and weight 90kg
    assert classification == 1  # Check if the classification is "Overweight"

def test_bmi_under_weight():
    bmi_value, classification = bmi.calculate_bmi(1.75, 50)  # Test with height 1.75m and weight 50kg
    assert classification == -1  # Check if the classification is "Underweight"

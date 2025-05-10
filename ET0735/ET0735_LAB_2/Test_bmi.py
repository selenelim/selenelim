import Lab2.bmi as bmi  # Import the updated bmi.py file

def test_bmi_under_weight():
    _, category = bmi.calculate_bmi(1.73, 50)
    assert category == -1

def test_bmi_normal_weight():
    _, category = bmi.calculate_bmi(1.73, 57)
    assert category == 0

def test_bmi_over_weight():
    _, category = bmi.calculate_bmi(1.73, 80)
    assert category == 1

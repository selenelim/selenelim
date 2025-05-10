import pytest
from Lab2 import calc_average, find_min_max, calc_median_temp

# Test for calc_average
def test_calc_average():
    # Test with a list of positive numbers
    result = calc_average([5, 10, 15, 20])
    assert result == 12.5  # The average should be 12.5

    # Test with a list containing negative numbers
    result = calc_average([-5, -10, 5, 10])
    assert result == 0  # The average should be 0

    # Test with an empty list
    result = calc_average([])
    assert result == "No numbers to calculate average."

# Test for find_min_max
def test_find_min_max():
    # Test with a list of positive numbers
    result = find_min_max([5, 10, 15, 20])
    assert result == (5, 20)  # Minimum is 5, Maximum is 20

    # Test with a list of negative and positive numbers
    result = find_min_max([-5, -10, 5, 10])
    assert result == (-10, 10)  # Minimum is -10, Maximum is 10

    # Test with an empty list
    result = find_min_max([])
    assert result == "No numbers to calculate min and max."

# Test for calc_median_temp
def test_calc_median_temp():
    # Test with an odd number of elements
    result = calc_median_temp([1, 2, 3, 4, 5])
    assert result == 3  # The median should be 3

    # Test with an even number of elements
    result = calc_median_temp([1, 2, 3, 4])
    assert result == 2.5  # The median should be the average of 2 and 3, which is 2.5

    # Test with an empty list
    result = calc_median_temp([])
    assert result == "No numbers to calculate median."

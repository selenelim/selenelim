import pytest
from Lab2 import find_min_max, calc_average, calc_median_temp

def test_find_min_max():
    # Test with a list of positive numbers
    float_list = [1.2, 3.4, 0.5, 9.0, 7.8]
    # Since this is the expected result based on the input list
    # min is 0.5, max is 9.0
    assert find_min_max(float_list) == (0.5, 9.0)
    
    # Test with a list of negative numbers
    float_list = [-1.2, -3.4, -0.5, -9.0, -7.8]
    # min is -9.0, max is -0.5
    assert find_min_max(float_list) == (-9.0, -0.5)
    
    # Test with an empty list
    float_list = []
    assert find_min_max(float_list) == (None, None)

def test_calc_average():
    # Test with a list of positive numbers
    float_list = [1.2, 3.4, 0.5, 9.0, 7.8]
    # The sum is 21.9, and the length is 5, so the average is 21.9 / 5 = 4.38
    assert calc_average(float_list) == 4.38
    
    # Test with an empty list
    float_list = []
    assert calc_average(float_list) == None

def test_calc_median_temp():
    # Test with an odd number of elements
    float_list = [1.2, 3.4, 0.5, 9.0, 7.8]
    # Sorted list is [0.5, 1.2, 3.4, 7.8, 9.0], and the median is 3.4
    assert calc_median_temp(float_list) == 3.4
    
    # Test with an even number of elements
    float_list = [1.2, 3.4, 0.5, 7.8]
    # Sorted list is [0.5, 1.2, 3.4, 7.8], the median is the average of 1.2 and 3.4, i.e., 2.3
    assert calc_median_temp(float_list) == 2.3
    
    # Test with an empty list
    float_list = []
    assert calc_median_temp(float_list) == None

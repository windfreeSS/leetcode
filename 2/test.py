import os
import random
import time
import datetime

def big_random():
    return random.randint(0,99999999999999999999999999999999999999999999999999999999999999999)
    pass

def generate_test_data():
    test_list=[]
    first_val=0
    second_val = big_random()
    result_val = first_val+ second_val
    num_str = str(first_val)[::-1]+'|'+str(second_val)[::-1]+'|'+str(result_val)[::-1]
    test_list.append(num_str)

    num_str = str(second_val)[::-1]+'|'+str(first_val)[::-1]+'|'+str(result_val)[::-1]
    test_list.append(num_str)


    for x in range(1,10):
        first_val = big_random()
        second_val = big_random()
        result_val = first_val+second_val
        num_str = str(first_val)[::-1]+'|'+str(second_val)[::-1]+'|'+str(result_val)[::-1]
        test_list.append(num_str)
        pass
    return test_list
    pass


def run_test():
    data_list= generate_test_data()

    before_ms = time.clock()
    for each_data in data_list:
        digit_list = each_data.split('|')
        each_cmd_str = '2.exe '+ digit_list[0] + ' ' + digit_list[1]
        # print(each_cmd_str)
        os.system(each_cmd_str)
        # print('stand_out:'+digit_list[2])
        pass
    pass
    after_ms = time.clock()

    
    for each_data in data_list:
        digit_list = each_data.split('|')
        each_cmd_str = '2_perfect.exe '+ digit_list[0] + ' ' + digit_list[1]
        # print(each_cmd_str)
        os.system(each_cmd_str)
        # print('stand_out:'+digit_list[2])
        pass
    pass
    third_ms = time.clock()
    print(after_ms-before_ms,"clock")
    print(third_ms-after_ms,"clock")

run_test()
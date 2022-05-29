
def example_method(a, b, lst) -> int:
    new_lst = []
    if a > 0:
        if b > 0:            
            for item in lst:
                new_lst.append(item)
                return new_lst
    else:
        return a * a

print(example_method(5, 6, [5, 6]))

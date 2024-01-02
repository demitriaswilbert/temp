import re

regexcode = r'(^.{0,3}#define\s+[\w\(\),]+)\s+(.+)'
regexcode1 = r'(^(?!//).{0,60})\s(//.{0,})$'
regexcode2 = r'(^(?!//).{70,})\s(//.{0,})$'

def get_length(line):
    match = re.match(regexcode, line)
    if match:
        return len(match.group(1))
    else: return 0

def get_length1(line):
    match = re.match(regexcode1, line)
    if match:
        return len(match.group(1))
    else: return 0

def get_length2(line):
    match = re.match(regexcode2, line)
    if match:
        return len(match.group(1))
    else: return 0

def align_numbers(spaces, line):
    match = re.match(regexcode, line)
    if match:
        return f'{match.group(1)}{" " * (spaces - len(match.group(1)))}{match.group(2)}\n'
    else:
        return line
    
def align_numbers1(spaces, line):
    match = re.match(regexcode1, line)
    if match:
        return f'{match.group(1)}{" " * (spaces - len(match.group(1)))}{match.group(2)}\n'
    else:
        return line

def align_numbers2(spaces, line):
    match = re.match(regexcode2, line)
    if match:
        return f'{match.group(1)}{" " * (spaces - len(match.group(1)))}{match.group(2)}\n'
    else:
        return line

with open('input.txt', 'r') as input_file:
    lines = input_file.readlines()

line_length = [0]
for line in lines:
    line_length.append(get_length(line))

line_length.sort(reverse=True)
print(line_length[0])   

formatted_lines = [align_numbers(line_length[0], line) for line in lines]

line_length = [0]
for line in lines:
    line_length.append(get_length1(line))

line_length.sort(reverse=True)
print(line_length[0])   

formatted_lines1 = [align_numbers1(line_length[0], line) for line in formatted_lines]

line_length = [0]
for line in lines:
    line_length.append(get_length2(line))

line_length.sort(reverse=True)
print(line_length[0])   

formatted_lines2 = [align_numbers2(line_length[0], line) for line in formatted_lines1]

with open('output.txt', 'w') as output_file:
    output_file.writelines(formatted_lines2)
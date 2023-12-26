import os
root_dir = "C:/Users/User/Documents/PlatformIO/Projects/temp"
filenames = []

for dir_, unused, files in os.walk(root_dir):
    for file_name in files:
        path = f'{dir_}\{file_name}'
        path = path.replace('\\', '/', -1)
        filenames.append(path)
        # rel_dir = os.path.abspath(file_name)
        # rel_file = os.path.abspath(file_name)
        # # if not rel_file.startswith("C:/Users/User/Documents/PlatformIO/Projects/Test Keyboard/.git"):
        # filenames.append(rel_file)

totalstring = ""

for i in filenames:
    totalstring += f'[@file: {i[len(root_dir)+1:]}]\n'
    with open(i, "rb") as file:
        totalstring += file.read().decode("utf-8") + '\n'
    print(f'Processed {i}')


with open("file1.txt", "wb") as file:
    file.write(totalstring.encode('utf-8'))



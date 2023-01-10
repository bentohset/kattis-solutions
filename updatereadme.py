import os

# The name of the folder that contains the folders to be scanned
src_folder = 'src'

# The name of the README file
readme_file = 'README.md'

# list to hold the names of the subfolders
subfolders = []

# walk through the src folder and get all subfolders
for dirpath, dirnames, filenames in os.walk(src_folder):
    for dirname in dirnames:
        if (dirpath == src_folder):
            subfolders.append(dirname)

# sort the list of subfolders
subfolders.sort()

# Update the README file with the sorted list of subfolders
with open(readme_file, 'r') as f:
    readme = f.read()

table_start = readme.index("| Folder | Description |")
table_end = readme.index("\n\n", table_start)
if table_end == -1:
    table_end = len(readme)

table = readme[table_start:table_end]

updated_table = table

for subfolder in subfolders:
    updated_table += f"\n| {subfolder} | Description of {subfolder} goes here |"

updated_readme = readme[:table_start] + updated_table + readme[table_end:]

with open(readme_file, 'w') as f:
    f.write(updated_readme)

print("Successfully Updated the README file with folders")

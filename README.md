# C-tools
--------
## Collection of some simple C-tools I made and found useful
-------
### List
- file_to_csv.c
  - simple description: makes a copy of the a file replacing all of the white spaces with commas]
  - How to use: put the text you want to covert into csv into a plain text file, and pass the file name to file_to_csv; the file make two new files one called  <original_file_name>_herder.csv and one called columns.csv
  - Copy and paste the contents of columns.csv to the second line of <original_file_name>_herder.csv
  -  <original_file_name>_herder.csv can now be uploaded to into your program using pandsas.read_csv("<original_file_name>_herder.csv")
- clock_list.c
  - simple description: linked list where final tail points to head 

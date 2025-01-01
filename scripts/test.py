# Specify the input and output file paths
input_file_path = "Application.txt"
output_file_path = "Application1.txt"

try:
    # Open the input file for reading
    with open(input_file_path, 'r') as input_file:
        # Read the content of the input file
        content = input_file.read()

    # Remove spaces and newlines from the content
    content_without_spaces_or_newlines = content.replace(' ', '').replace('\n', '')
    print(content_without_spaces_or_newlines)

    # Open the output file for writing
    with open(output_file_path, 'w') as output_file:
        # Write the modified content to the output file
        output_file.write(content_without_spaces_or_newlines)

    print("Spaces and newlines removed successfully.")
except FileNotFoundError:
    print(f"Error: The file {input_file_path} does not exist.")
except Exception as e:
    print(f"An error occurred: {e}")

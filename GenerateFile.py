import os

def create_cpp_file(problem_name, problem_link, folder_name):
    file_content = f"""/*
Author: TheSpectre
Problem Name: {problem_name}
Problem Link: {problem_link}
Idea:
Complexity:
Resource:
*/

"""
    folder_path = os.path.join(os.getcwd(), "Editorial/" + folder_name)
    if not os.path.exists(folder_path):
        os.makedirs(folder_path)

    file_name = f"{problem_name}.cpp"
    file_path = os.path.join(folder_path, file_name)
    with open(file_path, "w") as file:
        file.write(file_content)
    print(f"File '{file_name}' created successfully in folder '{folder_name}'!")

if __name__ == "__main__":
    try:
        with open("data.txt", "r") as input_file:
            for line in input_file:
                elements = line.strip().split(",")
                if len(elements) == 3:
                    problem_name, problem_link, folder_name = elements
                    create_cpp_file(problem_name, problem_link, folder_name)
                else:
                    print("Invalid format. Each line should contain three elements separated by commas.")
    except FileNotFoundError:
        print("data.txt file not found!")
    except Exception as e:
        print("An error occurred:", e)

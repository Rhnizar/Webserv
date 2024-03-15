# import sys

# def print_arguments(arguments):
#     for arg in arguments:
#         print(arg)

# if __name__ == "__main__":
#     arguments = sys.argv[1:]  # Exclude the script name itself
#     print_arguments(arguments)


#!/usr/bin/env python3

import cgi

# Get form data
form = cgi.FieldStorage()

# Get user and password from form
user = form.getvalue('user')
password = form.getvalue('password')

# Print user and password
print("Content-type:text/html\r\n\r\n")
print("<html>")
print("<head>")
print("<title>User and Password</title>")
print("</head>")
print("<body>")
print("<h2>User is: {}</h2>".format(user))
print("<h2>Password is: {}</h2>".format(password))
print("</body>")
print("</html>")


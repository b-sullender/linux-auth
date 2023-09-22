# Linux-Auth

Linux-Auth is a simple C program designed to authenticate users on Linux by checking their credentials against the shadow file. It provides a straightforward and portable solution for user authentication in C.

## Motivation

The motivation behind this project was to create a lightweight and easily portable tool for authenticating users in a Linux environment. The program utilizes the system's shadow file to validate usernames and passwords.

LICENSE TERMS
=============
```
This software is provided 'as-is', without any express or implied
warranty.  In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

(1) If any part of the source code or algorithm is used, it is requested that
    appropriate attribution is given to the authors by providing a link to
    the original repository or a reference to the authors name.
(2) Permission for use of this software is granted only if the user accepts
    full responsibility for any undesirable consequences; the authors accept
    NO LIABILITY for damages of any kind.

By using this software, you acknowledge that you have read and understood
these terms and agree to abide by them.
```

## Usage

To compile the program, use the following command:

```bash
gcc main.c -o auth -lcrypt
```

To run the program, you must have root or sudo privileges since it needs access to the shadow file, which contains user passwords. Use the following command:

```bash
sudo ./auth
```

## Contributing

Feel free to contribute to this project. You can report issues, suggest improvements, or submit pull requests.


# cpp-course

This repository is for my Academic Work Academy / Brights C++ course exercises.

---

## Git workflow

On this course, every assignment gets it's own branch.<br>
The git workflow is somewhat following:

1. On command line, go to the directory, where this repository exists. 
    To make sure you're in the main branch, enter the following command<br>
    ```
    git checkout main
    ```
    You can check the active branch with<br>
    ```
    git branch
    ```
2. Create a new branch from main with and switch to the new branch<br>
    ```
    git checkout -b <branch_name>
    ```
    for example:<br>
    ```
    git checkout -b Assignment_1
    ```
    to create a branch named Assignment_1.
3. Create a new directory and file and add it to the staging area. For example let's create
   Assignment_1 folder and file main.cpp inside, which we can then add:<br>
    ```
   mkdir Assignment_2
   cd Assignment_2
   touch main.cpp
   git add main.cpp
    ```
    Now we have added main.cpp to the git staging area, and we have moved in to the
    Assignment_2 directory on our terminal.
4. We can create a git commit with branch init message<br>
    ```
    git commit -m "Initializing branch"
    ```
5. We code our program and do adds/commits when we progress
6. When program is ready, we push the content in our local repository to the
   remote repository.
7. Now from the browser UI, we can create a pull request and compare this branch
   to the main branch.
8. When we have confirmed the pull request, we can jump to files changed page
   and copy our pull request link to assignment submission. Link looks something
   like this:<br>
   <https://github.com/kmoilane/cpp-course/pull/5/files>
9. Now others can add code reviews
10. After receiving code reviews, change the code accordingly, add files,
    commit them, and push.
11. Now we can merge it to the main branch. The Merge button can be found from,
    for example:<br>
    <https://github.com/kmoilane/cpp-course/pull/5>
    Scroll down a bit and there should be green "Merge pull request" button
12. This new branch has now been merged to main branch, which means the created
    files are now also in main branch.


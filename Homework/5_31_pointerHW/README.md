# Homework 5.31.2020

In this homework, we will do 2 things:
* Using Git/Github to upload and download codes.
* [Coding] Word sorting program!

## HW1. Using Git/Github to upload and download codes.

First let's learn how to upload. Go to the topmost directory you want to upload.

In terminal, start with
```sh
$ git init
```
This will initialize the root directory of repository.

Then we should add all files in here!
```sh
$ git add .
```

Then let's commit with some messages
```sh
$ git commit -m "Something to say"
```

After that let's add a REPOSITORY called "origin" which will be connected to remote GITHUB repository.
```sh
$ git remote add origin <GITHUB REPOSITORY TO UPLOAD>
```

Then finally, push(upload) origin to your GITHUB repository.
```sh
$ git push origin master
```

Last but not least, check if the files are pushed well in GITHUB page!

## HW2. [Coding] Word sorting program!

When you read dictionaries, words are sorted alphabetically. For this homework we will program a word sorting dictionary.
Of course we didn't learn about sorting, but thankfully I made a code for you to study how to sort :) 
Although the code in main.cpp is for sorting Int Arrays, you can easily adapt it for the words(String Arrays).
```c
void sortArr(int* intArr){
  // Add your code here! 
  for(int i=0; i<5; i++){
    int smallest = i;
    for(int j=i+1; j<5; j++){
      if(*(intArr+j)<*(intArr+smallest))
        smallest = j;
    }
    int tmp = *(intArr+i);
    *(intArr+i) = *(intArr+smallest);
    *(intArr+smallest) = tmp;
  }
  printArr(intArr);
  return;
}
```
So things you have to do is:
* Make a new c++ file called "charsort.cpp" for sorting words
* Copy codes from "main.cpp" to "charsort.cpp" and change some codes for char array(or pointer)

After testing your code, don't forget to push your code to GITHUB!




### Install Qt Creator

Since I am using the Windows operating system, I decided to install Qt Creator on my Windows system, as depicted below.

As of October 5, 2023, I am running Qt Creator version 11.0.2 (community).

![img](README/1696601299194-a6ae4211-8b3b-4de9-b05e-4d5e93265e50.png)

Unzip the test file and open it in Qt Creator. It will need to be configured initially, which may take a moment.

![img](README/1696601668529-7aeb94f2-53b9-40d3-9283-213120b28fc3.png)

If everything has proceeded smoothly, click the green right arrow button. A dialog box will appear, displaying copyright information and requesting that you enter your name or nickname. After entering your name or any other text, it will generate an image as illustrated below.

![img](README/1696602137456-c98e5670-b955-4e36-ba79-6037ea8bf20b.png)

#### Recommended Settings for Qt Creator

These settings are recommended by the officials's documentation, as depicted below.

##### Build & Run pane

1. General

![img](README/1696602352408-eacad671-745a-48af-8614-87bc4c2c9e4d.png)

1. Compile Output

![img](README/1696602432364-18e0a2c6-e415-46d3-89dc-329a228cc30e.png)

1. Application Output

![img](README/1696602469419-c09373a6-baff-4f05-ac19-aee8156f7bf8.png)

##### Debug pane

![img](README/1696602580138-ff802eb9-607e-4a19-9f4d-32c584a4379d.png)

##### Disable style analyzer

Qt Creator utilizes a code analyzer to ensure adherence to industry-standard "best practices", but disabling this feature may be more suitable for our needs. We must adjust the settings in both the Analyzer and C++ sections.

###### Analyzer pane

![img](README/1696602727111-0999c22f-c7d9-430b-a3ce-5f9c6f8cb383.png)

###### C++ pane

![img](README/1696602779696-379cb2b0-ddfd-40a5-92cf-ac553383e658.png)

Don't forget to click OK to save your settings.

### Configuring the Qt debugging helper

The helper has already been installed when we configure the test file automatically. If it doesn't work, we have to manually activate it. We can use a program to determine whether our Qt Creator is configured for the custom debugging helper. Fortunately, my Qt Creator works.

### Hash your name

Unzip the assignment code and open it in Qt Creator, as illustrated below.

![img](README/1696605636078-7486738c-7f56-4f4c-b829-50128c034509.png)

The debugger is a tool we can employ to gain insights into our program's behavior while it is running. The`nameHash`function, which serves as the core function in NameHash.cpp, calculates the hash code by assigning a numerical value to each character in the input name, ranging from 0 to 128. For this course, we are not required to delve into the mathematical principles behind the process.

![img](README/1696678918107-adff8c40-4b42-4076-a33a-af9bb11e7080.png)

The special value is 1967457.
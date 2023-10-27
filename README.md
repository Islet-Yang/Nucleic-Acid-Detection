# Nucleic-Acid-Detection
This is the assigned task of the summer 2022 OOP course (Compulsory professional course for the first-year undergraduates) of the Department of Automation of Tsinghua University.  

The project is designed in MVC structure (Model-View-Controller). The View Module is simple and you can replace to your own graphic interface. 
All classes are designed to be reusable enough, and the code comments are detailed.  

## Specific task requiremnets are as follow:  
1.1 **User Management**  
The users of this system include: subjects, field test information collection personnel (hereinafter referred to as "collection personnel"), laboratory test result entry personnel (hereinafter referred to as "entry personnel") and administrators. The subjects registered themselves, and the user information included: ID number (18 digits), name, and password, among which the ID number could not be repeated among all users. 
The collector and the entry clerk are also subjects because they are also subject to nucleic acid testing, and can only be designated by the administrator as the collector, the entry clerk or both among the registered subjects. The administrator is not unique, but also subject to nucleic acid testing, and its administrator identity can be specified by manually modifying the user file before the system runs for the first time.  

1.2 **User information is automatically read and saved**  
When the software starts to run, it automatically reads all user information saved in a specific text file; Automatically save all user information to a specific text file when the software exits the operation; Id numbers and names are stored in plain text. Passwords are stored in plain text or MD5 ciphertext. (MD5 class code is provided)  

1.3 **Collection of on-site detection information**  
After logging into the system, the collector can enter the test tube number (production date + time + 6-digit serial number), and add 1 or more subject information to the test tube (ID card of registered subjects, sampling date and time).  

1.4 **Input of laboratory test results**  
After logging in to the system, the logger can enter the test tube number (production date + time + 6-digit serial number), and add 1 test result information to the test tube (result entry date and time, positive/negative).  

1.5 **Sampling and result information is automatically read and saved**  
When the software starts to run, it automatically reads the sample and result information saved in specific text files; Automatically save all sample and result information to a specific text file when the software exits running; Both are stored in plain text.  

1.6 **Result Query**  
After the subjects log in to the system, the latest test results (sampling time, result entry time, positive/negative) are automatically listed.  

1.7 **Role Switching**  
When the user logs in, if there is a subject/collector/entry clerk/administrator at the same time, the user is prompted to select one role in the interim and switch to the 1.3~1.6 function.  




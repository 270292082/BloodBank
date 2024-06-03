# Helixire Lab : Blood Bank


### Option A: NZ Blood Bank System

Objective: The objective of this assignment is to develop an application to store and retrieve information of blood
donors and recipients (might include blood bank, hospital, or patient). The app contains several screens, each
might have relevant menu options.

![Blood_Bank-cropped](https://github.com/270292082/BloodBank/assets/171204053/e877441a-ed75-4904-9d42-bdb3d725d56c)

### 1. Introduction screen should include:
&ensp; • Name of the blood bank application, information about NZ Blood Bank, contact details and login /
registration option.

&ensp; • It must confirm the user category (donor or recipient) when login and registration (See the registration
screen in Task 3).

&ensp; • It can also be logged in and controlled by an administration account (See Task 8 for more details)

### 2. Donor’s screen should include:
&ensp; • A menu with the following options:

&ensp; o Procedure to donate blood.

&ensp; o Benefits of blood donation

&ensp; o Managing their information like updating their contact details,
address and health status and booking for the donation.

### 3. Donor’s registration screen should include:
&ensp; • First name, last name, dob, nationality, ethnicity, gender known underlying conditions (heart, ADHD,
diabetic, cancer, chickenpox etc…) blood group (optional if they don’t know, include none in the field),
contact no, email, physical address, last date of donation(optional), username and password.

&ensp; • Registration data can be stored or retrieved from corresponding files. (For example:
Donor_Registration file can store the donor’s data as like recipient...)

### 4. Login screen should include:
&ensp; • Donors and Recipients login must be validated and verified with information stored in corresponding
files (e.g., Donor_Registration or Recipient_Registration).

&ensp; • Provide Maximum three login attempts to access the system.

&ensp; Otherwise notify them login after some time


### 5. Recipient’s screen should include:
&ensp; • A menu with the following options:

&ensp; o Access donor’s information by blood group

&ensp; o Access donors by blood group and location

&ensp; o Potential donors contact details find by giving full name.

### 6. Recipient’s registration screen should include:
&ensp; • Name of the hospital or name of the blood bank or Patient name

&ensp; • physical address

&ensp; • Email

&ensp; • contact no

&ensp; • recipients_validation_status (valid registration to access blood).

### 7. Administration screen should include:
&ensp; • View the recipient information and donors’ information.

&ensp; • Update the donor’s blood testing reports.

&ensp; • Donor’s report

&ensp; • Report based on blood group.

&ensp; • Report based on location.

&ensp; • Recipient report

### 8. Booking screen should include:
&ensp; • Booking for the donation must access the donor’s full name, dob, recent health condition, date, time,
and time_availability_at_the_venue_of_donation.

o Time slot in between 9 to 4 pm, system should notify the donor if the slot taken by another.

• Hint: The system is supposed to serve 01 people at a time. A time slot can be a fixed duration (e.g., 1
hour).

Department of Electrical and Computer Engineering
Principles of Software Design
ENSF 480 û Fall 2026
Term Project

Total Mark: 100

Introduction:
In  this  project,  you  will  practice  the  complete  process  of  design  and  development  of  a
software project, using a systematic design methodology.

The last part of the course is focused on system level design and architecture and will be
achieved  in  an  ôActive  Learningö  pedagogic  approach.  It  means  that  while  theoretical
concepts will be discussed in lectures, the corresponding practical techniques to build some
design  components  will  be  developed  in  the  classroom,  or  during  the  lab  periods.  This
method shows you the initial directions and helps you to have a better vision on how to
continue the details later.

When you are working as a member of a group you should assume full responsibility and
your commitments must be achieved at your best capacity. All group members should be
available  during  the  lectures  and  labs,  to  participate  in  class/group  discussions,  and  to
achieve their own portion of work.

Flight Reservation Application

Project Overview: The purpose of this project is to analyze, design, and develop a stand-
alone  Flight  Reservation  System  using  object-oriented  principles  and  domain-driven
design  concepts.  The  primary  focus  will  be  on  Domain  Analysis  and  Design,  including
class  modeling,  associations,  use-case  definition,  and  applying  suitable  design  patterns.
The project will simulate the operations of a flight booking system for a single-user via a
standalone GUI application (not a web or client-server system).

The system should allow a user (acting as a customer, flight agent, or system administrator)
to:

ò  View available flights and flight details.
ò  Make, cancel, or modify a reservation.
ò  View booking history or flight schedule.
ò  Manage flight information (add, update, delete flights).
ò  Maintain customer information and payment record.

Users Roles:

Role
Customer

Flight Agent

Description
End-user booking flights

Employee
bookings

managing

System Administrator

Administer system data

Key Capabilities
Search flights, make/cancel
view
bookings,
reservations, etc.
Manage
customer  data,
modify  reservations,  view
schedules, etc.
Add/remove
flights,
manage routes and aircraft,
update schedules, etc.

Some of the Functional Requirements:

ò  Flight Search & View

ò  Search by origin, destination, date, and airline.
ò  Display available seats, flight time, and price.

ò  Booking Management
ò  Make new bookings.
ò  Cancel or modify existing reservations.
ò  Generate booking confirmation.

ò  Customer Management

ò  Add new customer profiles.
ò  View or edit customer details.
ò  Flight Management (Admin only)

ò  Add new flights or update existing flight details.
ò  Remove outdated flights.

ò  Payment Simulation

ò  Record payment information (simulated, not real processing).

ò  Database Connectivity

ò  Use SQLite or MySQL to store data locally.

ò  Monthly Promotion News

ò  Customers receive monthly promotion news (first day of each month)

ò  Other, if needed.

Some of the Non-Functional Requirements:

ò  Usability: Simple GUI for interaction using standard Java UI libraries.
ò  Portability: Runs as a stand-alone application on any desktop system.
ò  Maintainability: Use clear modular design with classes and layered architecture.
ò  Scalability: Design allows future extension (e.g., online booking, client server, etc).
ò  Other, as needed.

System Architecture:
A 3-layer design is recommended:
1.  Presentation Layer: GUI interface (view + input handling).
2.  Business Logic Layer: Core classes representing domain entities and operations.
3.  Data Layer: Handles persistence (database/file access).

Assessment Criteria:
At  the  end  you  project  will  be  evaluated  based  on  its  functionalities  and  the  following
criteria:

1.  How  well  separation  of  concepts  and  different  components  of  software  architecture

(entities, controllers, views, etc.) are considered and designed.

2.  How well major elements of quality design, such as modularity, cohesion, and coupling

are applied.

3.  How  well  the  non-functional  requirements  such  as  user-friendliness,  reusability,

maintainability, reliability, etc. are addressed in your application.

4.  How your system uses separation of concepts at different system levels: presentation
layer (view/boundary classes) and the domain layer (domain/entity classes), which are
glued together with control classes.

5.  How clear and accurate your UML diagrams are, and how well they represent your

final product.

6.  How well the projectÆs requirements are presented in your use-case diagram, and how

your use case diagram is traceable in your class diagram.

7.  How well the use-cases in your use case diagram are presented in use-case scenarios or

sequence diagrams.

Expected Deliverables

Design Phase (50 marks)
In this phase you should submit a Design Document that includes a clear description of
systemÆs requirements, and design artefacts as follows:

ò  Introduction to the system under study.

In this part you should have following paragraphs:

ò  Brief description of the system
ò  Followed  by  describing  some  of  the  major  and  relatively  more  complex
functionalities  such  as  process  of  browsing/selecting  a  flight,  the  process  of
booking a flight-ticket, and process making payment. In this part you can include
four activity diagrams as follows:

ò  An activity diagram that shows the process of logging in
ò  An activity diagram that shows the process browsing/selecting a flight
ò  An activity diagram that shows the process booking a flight
ò  An activity diagram that only shows the process making payment

ò  A systems use-case diagram.

ò  A detailed ôScenarioö for each use case:

In this part of your report, you should write a scenario (storyboarding) for each use case in
your  use-case  diagram.  All  candidate  objects  and  candidate  operations  should  be
underlined (use single-underline for objects and double-underline for operations).

ò  Four interaction diagrams: Draw sequence diagrams for four major use cases. These
use cases should be represented by control classes in your domain class diagram.
ò  Four state transition diagrams: One that shows the state of the entire system, one for
the process of making payment, one for a reservation object and one for a flight object.
ò  A class diagram: that shows classes, relationships among them, attributes, behaviours,

cardinalities, etc.

Note:

ò  Your class diagram should be traceable in your use-case scenarios. Mark will be

ò

deducted for classes that are not traceable in the use-case diagram.
In  your  class  diagram  you  donÆt  need  to  show  Java  library  classes  such  as
Exceptions, Buttons, String, ArrayList, etc.

ò  Make sure to clearly identify the stereotypes of your classes (such as <<entity>>,

<<control>>, <<boundary>>)

ò  You donÆt need to show constructors/destructor, getters/setters.
ò  Note:  at  the  final  stage  you  need  to  make  the  architecture  of  the  system  more:
reusable,  scalable,  maintainable,  reliable,  and  using  necessary  concepts  such  as
modular design, inheritance, realization, aggregation, composition, polymorphism,
and appropriate design patterns as needed.

ò  A Package Diagram, that shows how the three layers of the system interact with each
other. Make sure to show classes in each package and identify those that are public.

Implementation Phase (50 marks)
In  this  phase  you  will  implement  your  proposed  design  in  Java  GUI  and  your  chosen
database (SQLite or MySQL).

What to submit:

A single zip file that contains:

1.  A jar file that contains all compiled .class files.
2.  A zip file that contains all source code (.java files).

Due Date for Design and Implementation Parts: Monday Nov 30th, before 2 PM.

You need to demonstrate your working application, based on a schedule that will be posted
on the D2L.

During the demonstration, all team members MUST be present to assess their part of work.
If a member is absent the memberÆs implementation mark will be considered zero.



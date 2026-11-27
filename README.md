# ENSF 480 — Term Project (Group 23)
## How to Run the project
javac -d bin -cp lib/mysql-connector-j-26.10.0.jar src/*.java database/*.java
java -cp "bin;lib/mysql-connector-j-26.10.0.jar" Main

## Group Members
* Paolo Abad ( | paolo.abad@ucalgary.ca)
* Sarvesh Vettrivelan ( | sarvesh.vettrivelan@ucalgary.ca)
* Sharar Masud (30205753 | sharar.masud@ucalgary.ca)
* Steven Wu ( | steven.wu@ucalgary.ca)


 ## Project Overview

The Flight Reservation Application is a standalone, single-user Java desktop application. It simulates flight booking and administration while applying object-oriented design and domain-driven design concepts. The GUI opens with a choice of user role.

| Role | Planned capabilities |
| --- | --- |
| Customer | Search flights, make or cancel bookings, and review booking history. |
| Flight Agent | Manage customer profiles, modify reservations, and view flight schedules. |
| System Administrator | Add, update, or remove flights and manage routes, aircraft, and schedules. |

## Requirements

- Search by origin, destination, date, and airline. Display seat availability, flight times, and prices.
- Create, modify, and cancel reservations. Generate booking confirmations and retain booking history.
- Add, view, update, and remove customer profiles.
- Simulate payments and store payment records locally.
- Show customers a promotion on the first day of each month. The implementation rubric allows an in-app message.
- Persist application data locally using SQLite or MySQL.

## Architecture
| Layer | Responsibility |
| --- | --- |
| Presentation | Java GUI, role selection, and user input. |
| Business logic | Domain entities and operations for flights, customers, reservations, and payments. |
| Data | Local database access and persistence. |

## Deliverables

### Design document

- TBA

## Repository and Setup

- TBA: build and run instructions.

## Course References

- TBA.
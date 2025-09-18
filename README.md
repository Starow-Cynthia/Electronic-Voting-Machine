# Electronic-Voting-Machine
Electronic Voting Machine (EVM) using 8051 Microcontroller.  This project demonstrates a simple embedded system that records votes  between two candidates using push buttons, displays live results on  an LCD, and declares the winner automatically after voting ends.  Developed using Embedded C in Keil µVision and simulated in Proteus.
# 🗳️ Electronic Voting Machine (EVM) using 8051 Microcontroller

![Made with C](https://img.shields.io/badge/Made%20with-C-blue.svg)
![Microcontroller](https://img.shields.io/badge/MCU-8051-brightgreen.svg)
![Keil µVision](https://img.shields.io/badge/IDE-Keil%20µVision-orange.svg)
![Proteus](https://img.shields.io/badge/Simulation-Proteus-yellow.svg)

---

## 📖 Project Overview
This project demonstrates the design and implementation of a **digital Electronic Voting Machine (EVM)** using the **8051 microcontroller (AT89C51)**.  
It enables voting between two candidates using push buttons, provides **real-time results** on an LCD, and automatically announces the winner.  

If both candidates secure equal votes, the system employs a **pseudo-random tie-breaking logic** to ensure a fair outcome.  

This project was built as part of an **Embedded Systems course** to gain practical knowledge in **microcontroller programming, LCD interfacing, and circuit simulation**.

---

## 🎯 Objectives
- Replace manual vote counting with an automated system.  
- Provide a **low-cost and reliable voting machine**.  
- Ensure **real-time vote tracking** with an LCD display.  
- Automatically **resolve tie situations** without human bias.  

---

## ⚙️ Features
✔️ Startup welcome screen  
✔️ Voting for two candidates (Student 1 & Student 2)  
✔️ Real-time vote count display on 16x2 LCD  
✔️ Automatic winner announcement after all votes are cast  
✔️ Tie-breaking using random number generation  
✔️ User-friendly and simple embedded design  

---

## 🛠️ Components & Tools

### Hardware
- AT89C51 Microcontroller  
- 16x2 LCD Display (LM016L)  
- Push Buttons (2)  
- 10kΩ Potentiometer (for LCD contrast)  
- 5V Power Supply  
- Connecting wires & resistors  

### Software
- **Keil µVision** – Embedded C coding & HEX file generation  
- **Proteus Design Suite** – Circuit design & simulation  

---

## ⚙️ System Workflow

1. **Startup**  
   - LCD shows a welcome message:  
     *“Welcome to Class Election”*  

2. **Voting Phase**  
   - Two push buttons are used:  
     - Button 1 → Student 1  
     - Button 2 → Student 2  
   - Each press records a vote and updates the LCD in real-time.  

3. **End of Voting (18 votes in total)**  
   - The system compares votes.  
   - The winner is displayed automatically.  

4. **Tie Resolution**  
   - LCD shows *“It’s a Tie! Picking Winner...”*  
   - A pseudo-random generator (`rand()`) selects the winner.  

---

## 📂 Project Structure
EVM-8051/
│── src/ # Source code (Embedded C)
│ └── evm.c
│
│── simulation/ # Proteus simulation files
│ └── evm_circuit.pdsprj
│
│── docs/ # Documentation & Report
│ └── EVM_PROJECT_REPORT.pdf
│
│── screenshots/ # Simulation images
│ └── startup.png
│ └── voting.png
│ └── winner.png
│
└── README.md # Project description

---

## 🖥️ Code Highlights
- **LCD initialization & interfacing**  
- **Debounce logic** for push button presses  
- **Vote counting system** with live display  
- **Tie-breaking logic** using randomness  
- **Clear modular functions** for readability and testing  

---

## 📷 Screenshots & Outputs
*(Add your screenshots here later)*  

- **Startup Message**  
Welcome to Class
Election


- **Live Voting Example**
- Stud1 Vote = 07
Stud2 Vote = 05


- **Final Result**  


Voting Complete!
Winner: Student 1


- **Tie Case**
- It's a Tie!
Picking Winner...
Winner: Student 2


---

## 🚀 How to Run

1. Clone the repository:
 ```bash
 git clone https://github.com/your-username/EVM-8051.git
Open the src/evm.c file in Keil µVision.

Compile the code to generate a HEX file.

Open the circuit file in Proteus (simulation/evm_circuit.pdsprj).

Load the HEX file into the AT89C51 microcontroller in Proteus.

Run the simulation to test the voting process.

📌 Applications

Class elections – Ideal for small-scale student elections.

Club/Community polls – Simple and transparent voting system.

Prototype for real EVMs – Demonstrates basic working principles.

Educational project – Great for learning microcontroller basics, LCD interfacing, and embedded C.

✅ Conclusion

This project successfully demonstrates a working prototype of an Electronic Voting Machine (EVM) using an 8051 microcontroller.
It ensures:
✔️ Transparent & fair voting
✔️ Real-time display of results
✔️ Automated result announcement
✔️ Tie-breaking resolution

Through this project, I gained practical experience in:

Microcontroller programming

LCD interfacing

Embedded system design & simulation

👩‍💻 Developer: Starow Cynthia S
📍 Gandhi Institute of Technology and Management (GITAM), Bengaluru, India

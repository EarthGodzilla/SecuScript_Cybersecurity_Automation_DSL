# SecuScript_Cybersecurity_Automation_DSL
SecuScript is a domain-specific language (DSL) designed for cybersecurity automation in Security Operations Centers (SOCs).


How to Run the Project
1. Open terminal in project directory

2. Compile the program:
g++ -std=c++17 main.cpp Lexer.cpp Parser.cpp Executor.cpp -o Final

3. Run the executable:
./Final or Final.exe if using powershell or cmd

SecuScript is a domain-specific language (DSL) designed for cybersecurity automation in
Security Operations Centers (SOCs).
It allows users to issue standard English commands that are translated into executable security
tools such as Network scanners (nmap), Firewalls (ufw), and log monitoring pipelines
The system bridges the gap between human-readable intent and command-line execution,
enabling Faster response to threats, reduced errors, and accessibility for non-experianced users to
quickly get started and learn; while reducing the work load of those already working.

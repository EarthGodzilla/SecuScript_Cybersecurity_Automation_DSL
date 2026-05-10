#pragma once
#include <string>
#include <sstream>
using namespace std;   

class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual string execute() const = 0;
};

// Scan
class ScanCommand : public ASTNode {
public:
    string subnet, format;

    string execute() const override {
        stringstream output;
        output << "nmap -p- " << subnet;

        if (format == "json") {
            output << " -oJ output.json";
        }

        return output.str();
    }
};

// Block
class BlockCommand : public ASTNode {
public:
    string ip,firewall;

    string execute() const override {
        stringstream output;

        if (firewall == "ufw") {
            output << "ufw deny from " << ip;
        } else {
            output << "iptables -A INPUT -s " << ip << " -j DROP";
        }

        return output.str();
    }
};

// Monitor
class MonitorCommand : public ASTNode {
public:
    string file,event;

    string execute() const override {
        stringstream output;

        output << "tail -f " << file << " | grep '" << event << "'";

        return output.str();
    }
};
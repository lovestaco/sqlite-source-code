#!/bin/bash

# Create MyDB database with Students table
sqlite3 MyDB <<EOF
CREATE TABLE IF NOT EXISTS Students(SID INTEGER PRIMARY KEY);
INSERT OR IGNORE INTO Students(SID) VALUES (1);
INSERT OR IGNORE INTO Students(SID) VALUES (2);
INSERT OR IGNORE INTO Students(SID) VALUES (3);
EOF

# Create MyDBExtn database with Courses table
sqlite3 MyDBExtn <<EOF
CREATE TABLE IF NOT EXISTS Courses(name TEXT, SID INTEGER);
INSERT OR IGNORE INTO Courses(name, SID) VALUES ('Math', 1);
INSERT OR IGNORE INTO Courses(name, SID) VALUES ('Science', 1);
INSERT OR IGNORE INTO Courses(name, SID) VALUES ('History', 2);
INSERT OR IGNORE INTO Courses(name, SID) VALUES ('English', 3);
EOF

echo "Databases setup complete!"


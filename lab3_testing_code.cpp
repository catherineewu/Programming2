/**
/// Constructors, copy constructor, and copy assignment operator seem to work. 9/16, 3:50PM
cout << "Constructor and copying testing area___________________________________________________________" << endl;
ABS<int> t(3);
*t.list = 15;  // successfully resigns value
*(t.list + 2) = 8;
cout << *t.list << " " << *(t.list + 2) << endl;

ABS<int> i;
ABS<string> s(9);
ABS<int> c = i;
ABS<string> cs;
cs = s;

*c.list = 2;  // since c is shallow copy of i, edits both c and i
*(s.list + 3) = "yuh";
cout << *i.list << " " << *(s.list + 3) << endl;
cout << "_______________________________________________________________________________________________\n" << endl;
/// ____________________________________________________________________________________________________________

/// Push, pop, and peek stack functions, Data retrieval functions
/// Seems to work for integers and floats. FIXME: Doesn't work for strings or doubles. 9/16, 5:48PM
cout << "Push, pop, peek testing area___________________________________________________________" << endl;

// Testing int ABS:
ABS<int> g;
g.PrintStackInfo();
g.push(8);
g.PrintStackInfo();
g.push(19);
g.PrintStackInfo();
g.push(32);
g.PrintStackInfo();
cout << "Pop: " << g.pop() << endl;
g.PrintStackInfo();
cout << "Pop: " << g.pop() << endl;
g.PrintStackInfo();
cout << "Pop: " << g.pop() << endl;
g.PrintStackInfo();
cout << "Pop: " << g.pop() << endl;

// Testing float ABS:
ABS<float> h;
h.PrintStackInfo();
h.push(-3.4509);
cout << "Peek: " << h.peek() << endl;
h.PrintStackInfo();
h.push(0.0087);
h.PrintStackInfo();
h.push(5982);
h.PrintStackInfo();
cout << "Peek: " << h.peek() << endl;
cout << "Pop: " << h.pop() << endl;
h.PrintStackInfo();
cout << "Pop: " << h.pop() << endl;
h.PrintStackInfo();
cout << "Pop: " << h.pop() << endl;
h.PrintStackInfo();
cout << "Pop: " << h.pop() << endl;

cout << "_______________________________________________________________________________________________\n" << endl;

    void PrintStackInfo() {
        cout << "Size: " << getSize() << ", Capacity: " << getMaxCapacity() << ", Address: " << getData() << endl;
        cout << "Stack Data:" << endl;
        for (int i=0; i<size; i++) {
            cout << *(list + i) << " ";
        }
        for (int i=size; i<capacity; i++) {
            cout << "'" << *(list + i) << "' ";
        }
        cout << "\n" << endl;
    }

 */
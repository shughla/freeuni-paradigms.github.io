// struct, offset, size
// database, _, 8
// reference, 0, 4
// tables 4, 4

// dataCenter, _, 20
// coordinates 0, 4
// node 4, 8
// next, 16, 4

SP = SP - 4 // make space for queryScript variable

/**
SP + 12 servers
SP + 8 datacenterCoordinates
SP -> queryScript
**/


// line 1
// querySelector queryScript = RetrieveData(servers[0].coordinates);
R1 = SP + 12; // servers[0].coordinates (which is same ase &servers)
SP = SP – 4; // RetrieveData arguments
M[SP] = R1; // coordinates
CALL <RetrieveData>
SP = SP + 4 // free RetrieveData arguments
M[SP] = RV // assign to queryScript

// line 2
// datacenterCoordinates[*datacenterCoordinates] = 0;
R1 = M[SP + 8]; // datacenterCoordinates
R2 =.2 M[R1]; // *datacenterCoordinates
R2 = R2 * 2; // datacenterCoordinates + 2*datacenterCoordinates
R3 = R1 + R2;  // datacenterCoordinates[*datacenterCoordinates]
M[R3] =.2 0;


// line 3
// if (servers[2].node.reference > 3)
R1 = SP + 12 // servers
R2 = 20*2 // &servers[2]
R3 = M[R1 + R2] // servers[2].node.reference
BLE R1, 3, PC + 7*4

// line 4 (6 lines)
//    servers += ((struct database *) (servers->next[0].tables))->reference;
// this line is correct according to the handout
// will add comments later
R1 = M[SP + 12];
R2 = M[R1 + 16];
R3 = M[R2 + 8];
R4 = R3 * 16
R5 = R1 + R4
M[SP + 12] = R5


// line 5
//  return PopulateDatabase((struct database *)&servers, queryScript);
R1 = M[SP + 12] // servers
R2 = M[SP] // queryScript
SP = SP - 8
M[SP] = R1 // script
M[SP + 4] = R1 // server
CALL <PopulateDatabase>
SP = SP + 8; // free SetupServer arguments

// PopulateDatabase result is already in RV
// return
SP = SP + 4 // free queryScript
RET;

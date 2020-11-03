// struct, offset, size                                                                                                                                                                                   
// cpu, _, 8                                                                                                                                                                                              
// id, 0, 4                                                                                                                                                                                               
// cores 4, 4                                                                                                                                                                                             

// serverRoom, _, 16                                                                                                                                                                                      
// model 0, 4                                                                                                                                                                                             
// node 4, 8                                                                                                                                                                                              
// next, 12, 4                                                                                                                                                                                            

SP = SP - 4      // make space for localScript variable                                                                                                                                                   

/**                                                                                                                                                                                                       
SP + 12 servers                                                                                                                                                                                           
SP + 8 roomNumber                                                                                                                                                                                         
SP -> localScript                                                                                                                                                                                         
**/

// line 1                                                                                                                                                                                                 
// roomNumber[*roomNumber] = 0;                                                                                                                                                                           
R1 = M[SP + 8]; // roomNumber                                                                                                                                                                             
R2 =.2 M[R1]; // *roomNumber                                                                                                                                                                              
R3 = R2 * 2; // roomNumber + 2*roomNumber                                                                                                                                                                 
R4 = R1 + R3;  // roomNumber[*roomNumber]                                                                                                                                                                 
M[R3] =.2 0;                                                                                                                                                                                              

// line 2                                                                                                                                                                                                 
// if (servers[2].node.id > 3)                                                                                                                                                                            
R1 = M[SP + 12]; // servers                                                                                                                                                                                   
R2 = R1 + 32; // &servers[2]                                                                                                                                                                                  
R3 = M[R2 + 4] // servers[2].node.id                                                                                                                                                                     
BLE R1, 3, PC + 32

// line 3 (6 lines)                                                                                                                                                                                       
//    servers += ((struct cpu *) (servers->next[0].cores))->id;                                                                                                                                           
R1 = M[SP + 12];                                                                                                                                                                                          
R2 = M[R1 + 12]
R3 = M[ღ2 + 4];
R4 = 16 * R3;
R1 = M[SP + 12];
R2 = R1 + R4;
M[SP + 12] = R2;

// line 4                                                                                                                                                                                                 
// bootstrapScript localScript = GetSetupScript(servers[0].model);                                                                                                                                        
SP = SP - 4;
R1 = M[SP + 16];
R2 = M[R1];
M[SP] = R2;
CALL <GetSetupScript>
SP = SP + 4; // free GetSetupScript arguments                                                                                                                                                              
M[SP] = RV; // assign to localscript                                                                                                                                                                       

// line 5                                                                                                                                                                                                 
//  return SetupServers((struct cpu *)&servers, localScript);
SP = SP - 8;
M[SP] = SP + 20;
R1 = M[SP + 8];
M[SP + 4] = R1;
CALL <SetupServers>
SP = SP + 8; // free SetupServer arguments                                                                                                                                                                

// SetupServers result is already in RV                                                                                                                                                                   
// return                                                                                                                                                                                                 
SP = SP + 4 // free localScript                                                                                                                                                                           
RET;

import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.io.*;

class Passenger {
    private int id;
    private String FisrtName;
    private String LastName;
    private int PhoneNumber;
    private String Email;
    private String Nationality;
    private String FlightNumber;

    public Passenger (int id ,int PhoneNumber , String FisrtName , String LastName ,String Email,
    String Nationality , String FlightNumber)
    {
        this.id = id;
        this.Nationality = Nationality;
        this.Email = Email; 
        this.FisrtName = FisrtName;
        this.LastName = LastName;
        this.PhoneNumber = PhoneNumber;
        this.FlightNumber = FlightNumber;
    }
    public int getPassengerId(){

        return id;
    } 
    public String getFirstName(){
        return FisrtName;
    }
    public String getLastName(){

        return LastName;
    }
    public int getPhoneNumber(){

        return PhoneNumber;
    }
    public String getEmail(){

        return Email;
    }
    public String getFlightNumber(){

        return FlightNumber;
    }
    public String getNationality(){

        return Nationality;
    }
    @Override
    public String toString(){

        return 
        "Passenger ID: " + id + "\n" + 
         " First Name: " + FisrtName + "\n" +
          " Last Name: " + LastName + "\n" +
        " Phone Number: " + PhoneNumber + "\n" +
        " Email: " + Email + "\n" +
         " Nationality: " + Nationality + "\n" +
        " Flight Number: " + FlightNumber;
    }
}
class Employee {
    private int EmployeeId;
    private String FirstName;
    private String LastName;
    private String Email;
    private int PhoneNumber;
   private String Position;
    private String Department;

    public Employee(int EmployeeId , String FirstName , String LastName , String Email , int PhoneNumber , String Position , 
    String Department){

        this.EmployeeId = EmployeeId;
        this.FirstName = FirstName;
        this.LastName = LastName;
        this.Email = Email;
        this.PhoneNumber = PhoneNumber;
        this.Position = Position;
        this.Department = Department;
    }
    public int getEmployeeId(){

        return EmployeeId;
    }
    public String getFirstName(){

        return FirstName;
    }
    public String getLastName(){

        return LastName;
    }
    public String getEmail(){

        return Email;
    }
    public int getPhoneNumber(){

        return PhoneNumber;
    }
    public String getPosition(){

        return Position;
    }
    public String getDepartment(){

        return Department;
    }
    @Override
    public String toString(){
        return 
        "Employee ID: " + EmployeeId + "\n" +
        "First Name: " + FirstName + "\n" +
        "Last Name: " + LastName + "\n" +
        "Email: " + Email + "\n" +
        "Phone Number: " + PhoneNumber + "\n" +
        "Position: " + Position + "\n" +
        "Department: " + Department;
    }
}
class Flight {
    private String FlightNumber;
    private String Destination;
    private String TakeOffTime;
    private String LandingTime;
    private String Airline;
    private int Capacity;
    private int bookedSeats;

public Flight(String FlightNumber , String Destination , String TakeOffTime , 
String LandingTime , String Airline , int Capacity , int bookedSeats)
{

    this.FlightNumber = FlightNumber;
    this.Destination = Destination;
    this.TakeOffTime = TakeOffTime;
    this.LandingTime = LandingTime;
    this.Airline = Airline;
    this.Capacity = Capacity;
    this.bookedSeats = 0;
}
public String getFlightNumber(){

    return FlightNumber;

}
public String getDestination(){

    return Destination;
}
public String getTakeOffTime(){

    return TakeOffTime;
}
public String getLandingTime(){

    return LandingTime;
}
public String getAirline(){

    return Airline;
}
public int getCapacity(){

    return Capacity;
}
public int getBookedSeats(){

    return bookedSeats;
}
public void setBookedSeats(int bookedSeats){

    this.bookedSeats = bookedSeats;
}
public boolean bookSeat(){

    if (bookedSeats < Capacity){

        bookedSeats++;
        return true;
    }
    System.out.println("Cannot Book Seat(-Capacity Full-)");
    return false;
}
@Override
public String toString(){
    return 
    "Flight Number: " + FlightNumber + "\n" +
    "Destination: " + Destination + "\n" +
    "Take Off Time: " + TakeOffTime + "\n" +
    "Landing Time: " + LandingTime + "\n" +
    "Airline: " + Airline + "\n" +
    "Capacity: " + Capacity + "\n" +
    "Booked Seats: " + bookedSeats;
}
}
class Management{
    private List<Flight> flights;
    private List<Passenger> passengers;
    private List<Employee> employees;
    private static final String FLIGHT_FILE = "flights.txt";
    private static final String PASSENGER_FILE = "passengers.txt";
    private static final String EMPLOYEE_FILE = "employees.txt";

public Management(){

    flights = new ArrayList<>();
    passengers = new ArrayList<>();
    employees = new ArrayList<>();
  
}
public void addFlight(Flight flight){
    
    flights.add(flight);
    System.out.println("**********************************");
    System.out.println("Flight Added Successfully");
    System.out.println("**********************************");

}
public void displayFlights(){ 
    if(flights.isEmpty()){
        System.out.println("No Flights Available");
        return;

    }else{

        for (Flight flight : flights){

            System.out.println(flight);
            System.out.println("**********************************");
        }
    }
}
public void addEmployee(Employee employee){

    employees.add(employee);
    System.out.println("Employee Added Successfully");
}

public void displayEmployees(){

    if(employees.isEmpty()){
        System.out.println("No Employees Available");
        return;
    }else{
        for (Employee employee : employees){
            System.out.println(employee);
        }
    }
}

public void addPassenger(Passenger passenger){

    passengers.add(passenger);
    System.out.println("Passenger Added Successfully");
}
public void viewPassengersOnFlight(String flightNumber) {
    System.out.println("**********************************");
    System.out.println("Passengers on Flight " + flightNumber + ":");
    for (Passenger passenger : passengers) {
        if (passenger.getFlightNumber().equals(flightNumber)) {
            System.out.println(passenger);
            System.out.println("**********************************");
        }
    } 
}
 
public void bookSeats(int passengerId , String flightnumber){
    Flight flight = findFlight(flightnumber);
    Passenger passenger = findPassenger(passengerId);
    if (flight == null){
        System.out.println("Flight Not Found");
        return;
    }

    if (passenger == null){
        System.out.println("Passenger Not Found");
        return;
    }

    if(flight.getBookedSeats() >= flight.getCapacity()){
        System.out.println("Flight is Full");
        return;
    }

    passenger = new Passenger(passengerId, passenger.getPhoneNumber(), passenger.getFirstName(), 
    passenger.getLastName(), passenger.getEmail() , passenger.getNationality(), flightnumber);
    passengers.add(passenger);
    flight.setBookedSeats(flight.getBookedSeats() + 1);
    System.out.println("Seat Booked Successfully");

}
private Flight findFlight(String flightNumber) {
    for (Flight flight : flights) {
        if (flight.getFlightNumber().equals(flightNumber)) {
            return flight;
        }
    }
    
    return null;
}

private Passenger findPassenger(int passengerId) {
    for (Passenger passenger : passengers) {
        if (passenger.getPassengerId() == passengerId) {
            return passenger;
        }
    }
    
    return null;
}

public void saveData(){
    try(BufferedWriter flighWriter = new BufferedWriter(new FileWriter(FLIGHT_FILE));
    BufferedWriter passengerWriter = new BufferedWriter(new FileWriter(PASSENGER_FILE));
    BufferedWriter employeeWriter = new BufferedWriter(new FileWriter(EMPLOYEE_FILE))){

        for (Flight flight : flights){
            flighWriter.write(flight.getFlightNumber() + "," + flight.getDestination() 
            + "," + flight.getTakeOffTime() + "," + flight.getLandingTime() + "," 
            + flight.getAirline() + "," + flight.getCapacity() + "," + flight.getBookedSeats());
            flighWriter.newLine();
        }

        for (Passenger passenger : passengers){
            passengerWriter.write(passenger.getPassengerId() + "," + passenger.getPhoneNumber() 
            + "," + passenger.getFirstName() + "," + passenger.getLastName() + "," 
            + passenger.getEmail() + "," + passenger.getNationality() + "," 
            + passenger.getFlightNumber());
            passengerWriter.newLine();
        }

        for(Employee employee : employees){
            employeeWriter.write(employee.getEmployeeId() + "," + employee.getPhoneNumber() 
            + "," + employee.getFirstName() + "," + employee.getLastName() + "," 
            + employee.getEmail() + "," + employee.getPosition() + "," 
            + employee.getDepartment());
            employeeWriter.newLine();
        }

        System.out.println("Data Saved Successfully");

    }catch(IOException e){
        System.out.println("Error Saving Data");
    }
}

public void loadData(){
    try(BufferedReader flightReader = new BufferedReader(new FileReader(FLIGHT_FILE));
    BufferedReader passengerReader = new BufferedReader(new FileReader(PASSENGER_FILE));
    BufferedReader employeeReader = new BufferedReader(new FileReader(EMPLOYEE_FILE))){

        String line;
        while((line = flightReader.readLine()) != null){
            String[] data = line.split(",");
            if (data.length == 7){
                Flight flight = new Flight(data[0], data[1], data[2], data[3], data[4],
             Integer.parseInt(data[5]), Integer.parseInt(data[6]));
             flight.setBookedSeats(Integer.parseInt(data[6]));
            flights.add(flight);
            }else{
                System.out.println("Invalid flight data: " + line);
            }
            
        }

        while((line = passengerReader.readLine()) != null){
            String[] data = line.split(",");
            if (data.length == 7) {
                Passenger passenger = new Passenger(Integer.parseInt(data[0]), Integer.parseInt(data[1]),
             data[2], data[3], data[4], data[5], data[6]);
            passengers.add(passenger);
            }else{
                System.out.println("Invalid passenger data: " + line);
            }    
            
        }

        while((line = employeeReader.readLine()) != null){
            String[] data = line.split(",");
            if (data.length == 7){
            Employee employee = new Employee(Integer.parseInt(data[0]), data[1], data[2], data[3], Integer.parseInt(data[4]), data[5], data[6]);
            employees.add(employee);
        }else{
            System.out.println("Invalid employee data: " + line);
        }
    }
        System.out.println("Data Loaded Successfully");

    }catch(IOException e){

        System.out.println("Error Loading Data" + e.getMessage());
    }

}

}

public class AirPortSystem {
    public static void main(String[] args) {
        Management management = new Management();
        Scanner input = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\nAirport System Interface");
            System.out.println("**********************************");
            System.out.println("1. Add Flight");
            System.out.println("2. Display Flights");
            System.out.println("3. Add Passenger");
            System.out.println("4. View Passengers on Flight");
            System.out.println("5. Book Seat");
            System.out.println("6. Save Data");
            System.out.println("7. Load Data");
            System.out.println("8. Add Employee");
            System.out.println("9. Display Employees");
            System.out.println("10. Exit");
            System.out.println("**********************************");
            System.out.print("Enter Choice: ");
            
            choice = input.nextInt();
            input.nextLine();

            switch (choice) {
                case 1:
                    System.out.print("Enter Flight Number: ");
                    String flightNumber = input.nextLine();
                    System.out.print("Enter Destination: ");
                    String destination = input.nextLine();
                    
                    String takeOffTime;
                    while (true) {
                        System.out.print("Enter Take Off Time (0-24): ");
                        takeOffTime = input.nextLine();
                        try {
                            int takeOffHour = Integer.parseInt(takeOffTime);
                            if (takeOffHour >= 0 && takeOffHour <= 24) {
                                break;
                            } else {
                                System.out.println("Invalid Take Off Time. Please enter a value between 0 and 24.");
                            }
                        } catch (NumberFormatException e) {
                            System.out.println("Invalid input. Please enter a numeric value.");
                        }
                    }

                    String landingTime;
                    while (true) {
                        System.out.print("Enter Landing Time (0-24): ");
                        landingTime = input.nextLine();
                        try {
                            int landingHour = Integer.parseInt(landingTime);
                            if (landingHour >= 0 && landingHour <= 24) {
                                break;
                            } else {
                                System.out.println("Invalid Landing Time. Please enter a value between 0 and 24.");
                            }
                        } catch (NumberFormatException e) {
                            System.out.println("Invalid input. Please enter a numeric value.");
                        }
                    }

                    System.out.print("Enter Airline: ");
                    String airline = input.nextLine();
                    System.out.print("Enter Capacity: ");
                    int capacity = input.nextInt();
                    input.nextLine();
                    management.addFlight(new Flight(flightNumber, destination, takeOffTime, landingTime, airline, capacity, 0));
                    break;
                case 2:
                    management.displayFlights();
                    break;
                case 3:
                    System.out.print("Enter Passenger ID: ");
                    int id = input.nextInt();
                    input.nextLine();
                    System.out.print("Enter First Name: ");
                    String firstName = input.nextLine();
                    System.out.print("Enter Last Name: ");
                    String lastName = input.nextLine();
                    System.out.print("Enter Phone Number: ");
                    int phoneNumber = input.nextInt();
                    input.nextLine();
                    System.out.print("Enter Email: ");
                    String email = input.nextLine();
                    System.out.print("Enter Nationality: ");
                    String nationality = input.nextLine();
                    System.out.print("Enter Flight Number: ");
                    String flightNumber1 = input.nextLine();
                    management.addPassenger(new Passenger(id, phoneNumber, firstName, lastName, email, nationality, flightNumber1));
                    break;
                case 4:
                    System.out.println("Enter Flight Number: ");
                    String flightNumber2 = input.nextLine();
                    management.viewPassengersOnFlight(flightNumber2);
                    break;
                case 5:
                    System.out.println("Enter Passenger ID: ");
                    int passengerId = input.nextInt();
                    input.nextLine();
                    System.out.println("Enter Flight Number: ");
                    String flightNumber3 = input.nextLine();
                    management.bookSeats(passengerId, flightNumber3);
                    break;
                case 6:
                    management.saveData();
                    break;
                case 7:
                    management.loadData();
                    break;
                case 8:
                    System.out.println("Enter Employee ID: ");
                    int employeeId = input.nextInt();
                    input.nextLine();
                    System.out.println("Enter First Name: ");
                    String employeeFirstName = input.nextLine();
                    System.out.println("Enter Last Name: ");
                    String employeeLastName = input.nextLine();
                    System.out.println("Enter Email: ");
                    String employeeEmail = input.nextLine();
                    System.out.println("Enter Phone Number: ");
                    int employeePhoneNumber = input.nextInt();
                    input.nextLine();
                    System.out.println("Enter Position: ");
                    String position = input.nextLine();
                    System.out.println("Enter Department: ");
                    String department = input.nextLine();
                    management.addEmployee(new Employee(employeeId, employeeFirstName, employeeLastName, employeeEmail, employeePhoneNumber, position, department));
                    break;
                case 9:
                    management.displayEmployees();
                    break;
                case 10:
                    System.out.println("Exiting Program");
                    break;
                default:
                    System.out.println("Invalid Choice, Please Try Again");
            }
        } while (choice != 10);
        input.close();
    }
}

public class VoterFactory{
  public voterInstance newVoter(int age, String address, String fn, String ln){
    if (age < 18){
      System.out.println("Voter can't be under 18") ;
    } else {
      System.out.println(fn + " " + ln + " has been registered to vote.");
      return new voterInstance(age, address, fn, ln);
      
    } 
    return null;
  } 
  
  private class voterInstance implements Voter{
    private boolean voidBallot = false;
    String ballot;
    private int ballotTries = 0;
    private boolean registration = false;
    private boolean identity = false;
    private String address;
    private int voted = 0;
    private boolean hasVoted = false;
    private boolean affidavit = false;
    private boolean absenteeBallot = false;
    private int age;
    private String firstName;
    private String lastName;
    
    private voterInstance(int a, String s, String f, String l){
    this.age = a;
    this.address = s;
    this.firstName = f;
    this.lastName = l;
    }

    public void name(){
      if (firstName.contains(firstName) && lastName.contains(lastName)){
        identity = true;
      }
    }

    public boolean address(String home){
      address = home;
      if(address.contains(address)){
        return true;
      }
      return false;
    }

    public void registration(){
      if (identity == true ){
        registration = true;
      }
    }
    public void hasVoted(){
      if (ballotTries == 0){
        hasVoted = false;
      }
      if (ballotTries == 1 || ballotTries == 2 || ballotTries == 3){
        if (voidBallot == true){
          hasVoted = false;
        }
      }
      if (ballotTries == 4) {
        hasVoted = true;
      }
    }
    public void affidavit(){
      if (registration == false){
        affidavit = true;
      }
      if (absenteeBallot == true){
        affidavit = true;
      }
    }

    public void voidBallot(){
      if (voidBallot == true){
        ballot=null;
        ballotTries++;
      }
    }

    public void absenteeBallot(){
      if (absenteeBallot == true){
        hasVoted = true;
      }
    }

    public void voterBallot(){
      if (affidavit == true){
        ballot = "Red Envolope";
      }
      if (hasVoted == false){
        ballot = "Black Envolope";
      }
    }
  }
}

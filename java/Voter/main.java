class Main {
  public static void main(String[] args) {
    VoterFactory VF = new VoterFactory();
    Voter john = VF.newVoter(20, "123", "john", "smith");
  }
}

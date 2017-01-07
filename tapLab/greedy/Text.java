public class Text implements Comparable<Text> {

  private int length;
  private int frequency;
  private int index;


  public Text(int length, int frequency, int index) {
    this.length = length;
    this.frequency = frequency;
    this.index = index;
  }

  public int compareTo(Text text){
    return (length * frequency - text.length * text.frequency);
  }

  public int getLength() {
    return length;
  }

  public int getIndex() {
    return index;
  }

  public int getFrequency() {
    return frequency;
  }

}

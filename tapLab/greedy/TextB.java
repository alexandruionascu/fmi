public class TextB implements Comparable<TextB> {

  private int length;
  private int index;


  public TextB(int length, int index) {
    this.length = length;
    this.index = index;
  }

  public int compareTo(TextB text){
    return (length - text.length);
  }

  public int getLength() {
    return length;
  }

  public int getIndex() {
    return index;
  }

}

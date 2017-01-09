public class Task implements Comparable<Task>{
    private int profit;
    private int deadline;
    private int duration;
    private int index;

    public Task(int profit, int deadline, int duration, int index) {
        this.profit = profit;
        this.deadline = deadline;
        this.duration = duration;
        this.index = index;
    }

    public int getProfit() {
        return profit;
    }

    public void setProfit(int profit) {
        this.profit = profit;
    }

    public int getDeadline() {
        return deadline;
    }

    public void setDeadline(int deadline) {
        this.deadline = deadline;
    }

    public int getDuration() {
        return duration;
    }

    public void setDuration(int duration) {
        this.duration = duration;
    }

    public int getIndex() {
        return index;
    }

    public void setIndex(int index) {
        this.index = index;
    }

    @Override
    public int compareTo(Task task) {
        return this.getDeadline() - task.getDeadline();
    }
}

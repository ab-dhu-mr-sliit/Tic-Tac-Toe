int switchPlayer(int currentTurn, int totalPlayers) {
    return (currentTurn + 1) % totalPlayers;
}

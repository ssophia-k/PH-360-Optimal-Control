Part a:
    Untrained:
        --- Reward Statistics ---
        Average: 9.2
        Standard deviation: 0.6
        Minimum: 8.0
        Maximum: 10.0
    Trained 100 episodes (qlearning_agent_policy_20260428_025702.pth):
        --- Reward Statistics ---
        Average: 120.6
        Standard deviation: 87.80000000000001
        Minimum: 39.0
        Maximum: 267.0
    Trained 100 episodes (qlearning_agent_policy_20260428_030107.pth):
        --- Reward Statistics ---
        Average: 206.3
        Standard deviation: 78.61303963083986
        Minimum: 105.0
        Maximum: 373.0
    Trained 500 episodes (qlearning_agent_policy_20260428_032406.pth):
        --- Reward Statistics ---
        Average: 216.0
        Standard deviation: 18.788294228055936
        Minimum: 184.0
        Maximum: 244.0

Part b:
    Naive was the noisiest; we get high variance because past rewards "pollute" each action's gradient signal.
    Causality trick seems to smooth it out somewhat, because each action only gets credit for future reward. 
    Causality + baseline is the most stable becausethe centering reduces variance even more, so the curve trends upward more consistently even if the ceiling is similar. 
    But we note that REINFORCE performs worse than DQN regardless of variant. It never beat the 200 reward line, which DQN did. In REINFORCE, the agent collects one episode, does one gradient update, then stops using that information. The DQN training process, however, stores every (s, a, r, s') transition in a replay buffer and resamples from it many times. Thus, a single experience from an earlier episode might still be used for gradient updates in later episodes.
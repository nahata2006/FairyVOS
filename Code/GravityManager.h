#pragma once
#include <Eigen/Core>

class GravityManager {
public:
    static float current_gravity;
    
    static void UpdateFromSensors(const Eigen::Vector3f& imu_embarqué, 
                                const Eigen::Vector3f& imu_fixe) {
        // Calcul du delta G
        float delta = (imu_embarqué - imu_fixe).norm();
        
        // Seuil de recalibration (0.3 m/s²)
        if(delta > 0.3f) {
            current_gravity = imu_fixe.norm(); 
            RequestSLAMReset();
        }
    }
    
    static void RequestSLAMReset(); // À implémenter
};
